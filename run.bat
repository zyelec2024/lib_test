@move .\build\lib_test.exe .\object\lib_test.exe

@cd .\object

lib_test.exe %1

:end
@cd ..
