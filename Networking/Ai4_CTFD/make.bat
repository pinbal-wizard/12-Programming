docker build -t my-website /Webpage
Rem docker run --cap-add SYS_PTRACE -e 'ACCEPT_EULA=1' -e 'MSSQL_SA_PASSWORD=1234567890' -p 1433:1433 --name azuresqledge -d mcr.microsoft.com/azure-sql-edge
docker run -d -p 8080:80 --name superSecureServices my-website 