#include <stdlib.h> 
#include <unistd.h>

int main(int argc,char **argv,char **envp)

{
  __UINT32_TYPE__ __rgid;
  __UINT32_TYPE__ __ruid;
  int iVar1;
  __UINT32_TYPE__ gid;
  __UINT32_TYPE__ uid;
  
  __rgid = 3003;
  __ruid = 3003;
  setresgid(__rgid,__rgid,__rgid);
  setresuid(__ruid,__ruid,__ruid);
  iVar1 = system("/usr/bin/env echo Exploit me");
  return iVar1;
}
