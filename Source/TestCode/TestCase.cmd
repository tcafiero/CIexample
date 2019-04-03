rem @echo off
rem cd "%~dp0"
node ".\Source\TestCode\HILgateway.js" COM52 5000 500 10
rem node "%~dp0\HILgateway.js" COM52 5000 500 10
IF %ERRORLEVEL% == 1 (
   echo HIL Test Not Passed
   exit /b %errorlevel%
   )
IF %ERRORLEVEL% == 0  (
   echo HIL Test Passed
   exit /b %errorlevel%
)
