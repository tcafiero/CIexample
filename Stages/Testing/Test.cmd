@echo off
node "./Source/TestCode/HILTestSimulator.js" COM5 10000 500 10
IF %ERRORLEVEL% == 1 (
   echo HIL Test Not Passed
   exit /b %errorlevel%
   )
IF %ERRORLEVEL% == 0  (
   echo HIL Test Passed
   exit /b %errorlevel%
)
