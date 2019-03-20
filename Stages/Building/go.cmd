@echo off

matlab -nosplash -nodesktop -minimize -noFigureWindows -r "generate" -logfile .\logfile.log | more
:loop
tasklist /fi "imagename eq MATLAB.exe" |find ":" > nul
if errorlevel 1 goto loop
