@mkdir build
@cd build

cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
@REM cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ../project
@ if errorlevel 1 goto end

cmake --build . 
@ if errorlevel 1 goto end

:end
@cd ..
@REM clean.bat
@REM @ exit
@REM @pause
