; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=EyeProtect
AppVerName=EyeProtect 1.0.0
AppPublisher=WenjieBao
DefaultDirName={pf}\EyeProtect
LicenseFile=D:\cpp\EyeProtect\agreement.txt
InfoAfterFile=D:\cpp\EyeProtect\userFile.txt
OutputDir=D:\cpp\out
OutputBaseFilename=EyeProtect
SetupIconFile=D:\cpp\EyeProtect\logo.ico
Password=2020
;Encryption=yes
Compression=lzma
SolidCompression=yes
[files]
Source: "D:\cpp\EyeProtect\*"; DestDir: "{app}"
Source: "D:\cpp\EyeProtect\iconengines\*"; DestDir: "{app}\iconengines"
Source: "D:\cpp\EyeProtect\imageformats\*"; DestDir: "{app}\imageformats"
Source: "D:\cpp\EyeProtect\platforms\*"; DestDir: "{app}\platforms"
Source: "D:\cpp\EyeProtect\styles\*"; DestDir: "{app}\styles"
Source: "D:\cpp\EyeProtect\translations\*"; DestDir: "{app}\translations"
[icons]
Name: "{userdesktop}\EyeProtect";Filename: "{app}\EyeProtect.EXE"; WorkingDir: "{app}"

[Registry]
Root: HKCU; Subkey: "SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\MyComputer\NameSpace\{{9E8D2FA1-591C-11D0-BF52-0020AF32BD64}"; ValueType:string;
Root: HKCR; Subkey: "CLSID\{{9E8D2FA1-591C-11D0-BF52-0020AF32BD64}"; ValueType: string; ValueData: "ϵͳ������";
Root: HKCR; Subkey: "CLSID\{{9E8D2FA1-591C-11D0-BF52-0020AF32BD64}\Shell\Open\Command"; ValueType:string; ValueData:"{app}\EyeProtect.EXE";
Root: HKCR; Subkey: "CLSID\{{9E8D2FA1-591C-11D0-BF52-0020AF32BD64}\DefaultIcon"; ValueType:string; ValueData:"{app}\logo.ico";
