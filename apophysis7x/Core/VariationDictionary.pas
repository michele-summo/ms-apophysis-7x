unit VariationDictionary;

interface
  uses System.Classes, System.Generics.Collections;
  type TVariationDictionary = class
    private
      _dict: TDictionary<integer, double>;

      function GetData(index: integer) : double;
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
  const EPS: double = 1E-10;

  constructor TVariationDictionary.Create;
  begin
    _dict := TDictionary<integer, double>.Create;
  end;

  destructor TVariationDictionary.Destroy;
  begin
     _dict.Destroy;
     _dict := nil;

     inherited;
  end;

  function TVariationDictionary.GetData(index: Integer): Double;
  begin
    Result := 0.0;

    if not _dict.TryGetValue(index, Result) then
    begin
      if (_dict.Count = 0) and (index = 0) then
      begin
        Result := 1.0;
      end
      else begin
        Result := 0.0;
      end;
    end;
  end;

  procedure TVariationDictionary.SetData(index: Integer; value: Double);
  begin
    if (value <= EPS) and (_dict.ContainsKey(index)) then
    begin
      _dict.Remove(index);
    end
    else if (value > EPS) then
    begin
      _dict.AddOrSetValue(index, value);
    end
  end;

  function TVariationDictionary.Count: Integer;
  begin
    Result := _dict.Count;
  end;

  function TVariationDictionary.GetEnumerator: TEnumerator<integer>;
  begin
    Result := _dict.Keys.GetEnumerator;
  end;

  function TVariationDictionary.Keys: TEnumerable<integer>;
  begin
    Result := _dict.Keys;
  end;
end.

