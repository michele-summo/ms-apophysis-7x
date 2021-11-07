unit VariationDictionary;

interface
  uses System.Classes, System.Generics.Collections;
  type TVariationDictionary = class
    strict private
      type
          TEnumerator = class(TEnumerator<integer>)
      private
        _array: TList<integer>;
        _enum: TEnumerator<integer>;
      public
        function DoGetCurrent: integer; override;
        function DoMoveNext: boolean; override;
        constructor Create(pToEnum: TEnumerable<integer>);
      end;
    private
      _dict: TDictionary<integer, double>;
      _fastArray: array of double;

      function GetData(index: integer) : double;
      function GetDataDict(index: integer) : double;
      procedure SetData(index: integer; value: double);
    public
      constructor Create;
      destructor Destroy;  override;

      property Item[index: integer]: double read GetData write SetData; default;
      function GetEnumerator: TEnumerator<integer>;
      function Count: integer;
      function Keys: TEnumerable<integer>;
  end;
implementation
  uses XFormMan;

  const EPS: double = 1E-10;

  constructor TVariationDictionary.Create;
  begin
    _dict := TDictionary<integer, double>.Create;
    SetLength(_fastArray, NrVar);
  end;

  destructor TVariationDictionary.Destroy;
  begin
     _dict.Destroy;
     _dict := nil;

     SetLength(_fastArray, 0);

     inherited;
  end;

  function TVariationDictionary.GetDataDict(index: Integer): Double;
  begin
    Result := 0.0;

    if not _dict.TryGetValue(index, Result) then
    begin
      if (index = 0) then
      begin
        Result := 1.0;
      end
      else begin
        Result := 0.0;
      end;
    end;
  end;

  function TVariationDictionary.GetData(index: Integer): Double;
  begin
    Result := _fastArray[index];
  end;

  procedure TVariationDictionary.SetData(index: Integer; value: Double);
  var
    isZero: boolean;
    valueZero: double;
  begin
    if index = 0 then
    begin
      isZero := ( 1-EPS <= value ) and ( value <= 1+EPS );
    end
    else
    begin
      isZero := ( -EPS <= value ) and ( value <= EPS );
    end;
    if isZero and (_dict.ContainsKey(index)) then
    begin
      _dict.Remove(index);
    end
    else if not isZero then
    begin
      _dict.AddOrSetValue(index, value);
    end;

    _fastArray[index] := GetDataDict(index);
  end;

  function TVariationDictionary.Count: Integer;
  begin
    Result := _dict.Count;
  end;

  function TVariationDictionary.GetEnumerator: TEnumerator<integer>;
  begin
    //Result := _dict.Keys.GetEnumerator;
    Result := TVariationDictionary.TEnumerator.Create(_dict.Keys);
  end;

  function TVariationDictionary.Keys: TEnumerable<integer>;
  begin
    Result := _dict.Keys;
  end;

  constructor TVariationDictionary.TEnumerator.Create(pToEnum: TEnumerable<integer>);
  begin
    Inherited Create;

    _array := TList<integer>.Create;
    _array.AddRange(pToEnum);
    _enum := _array.GetEnumerator;
  end;

  function TVariationDictionary.TEnumerator.DoMoveNext: boolean;
  begin
    Result := false;
    if _enum <> nil then
    begin
      Result := _enum.MoveNext;
      if not Result then
      begin
        _enum.Destroy;
        _array.Destroy;

        _enum := nil;
        _array := nil;
      end;
    end;
  end;

  function TVariationDictionary.TEnumerator.DoGetCurrent: integer;
  begin
    Result := _enum.Current; // Based on your example, it's value you want to extract
  end;
end.
