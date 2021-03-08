Documentation to Zip a folder using C++.
------------------------------------------

- This program works by getting the input for the source and destination file path for   the   folder to be zipped.
- The source and destination path are written to a Powershell script file in the format 
'Compress-Archive -LiteralPath '<source path>' -DestinationPath '<destination path>'' 
- This creates a poweshell script file in the location of this program.
- Once the file is created,the execution policy to start the Powershell is created using the command 'start powershell.exe Set-ExecutionPolicy RemoteSigned'
- Then Powershell is started using the command 'start powershell.exe .\\zip.ps1'
- The powershell script file is then executed to zip the source folder in the destination Path.

(This solution works only on Windows platform because it uses the Command Prompt(Windows Only) and Powershell.)