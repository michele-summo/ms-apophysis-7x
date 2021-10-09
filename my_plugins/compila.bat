msbuild -property:Configuration=Release "%~dp0\%1\%1.vcxproj"
msbuild -property:Configuration=Release -property:Platform=x64 "%~dp0\%1\%1.vcxproj"
move /y "%~dp0\%1\bin\%1.Win32.dll" "%~dp0\bin\%1.x86.dll"
move /y "%~dp0\%1\bin\%1.x64.dll" "%~dp0\bin\%1.x64.dll"