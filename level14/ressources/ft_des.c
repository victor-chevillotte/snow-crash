#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * ft_des(char *param_1)

{
  char cVar1;
  char *pcVar2;
  unsigned int uVar3;
  char *pcVar4;
  char bVar5;
  unsigned int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  bVar5 = 0;
  pcVar2 = strdup(param_1);
  local_1c = 0;
  local_20 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (unsigned int)bVar5 * -2 + 1;
    } while (cVar1 != 0);
    if (~uVar3 - 1 <= local_20) {
      return pcVar2;
    }
    if (local_1c == 6) {
      local_1c = 0;
    }
    if ((local_20 & 1) == 0) {
      if ((local_20 & 1) == 0) {
        local_14 = 0;
        while (local_14 < (int)"0123456"[local_1c]) {
          pcVar2[local_20] = pcVar2[local_20] + -1;
          if (pcVar2[local_20] == 0x1f) {
            pcVar2[local_20] = '~';
          }
          local_14 = local_14 + 1;
        }
      }
    }
    else {
      local_18 = 0;
      while (local_18 < (int)"0123456"[local_1c]) {
        pcVar2[local_20] = pcVar2[local_20] + 1;
        if (pcVar2[local_20] == 0x7f) {
          pcVar2[local_20] = ' ';
        }
        local_18 = local_18 + 1;
      }
    }
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
  } while( 1 );
}

int main() {
    char *tokens[] = {
        "I`fA>_88eEd:=`85h0D8HE>,D",
        "7`4Ci4=^d=J,?>i;6,7d416,7",
        "<>B16\\AD<C6,G_<1>^7ci>l4B",
        "B8b:6,3fj7:,;bh>D@>8i:6@D",
        "?4d@:,C>8C60G>8:h:Gb4?l,A",
        "G8H.6,=4k5J0<cd/D@>>B:>:4",
        "H8B8h_20B4J43><8>\\ED<;j@3",
        "78H:J4<4<9i_I4k0J^5>B1j`9",
        "bci`mC{)jxkn<\"uD~6%g7FK`7",
        "Dc6m~;}f8Cj#xFkel;#&ycfbK",
        "74H9D^3ed7k05445J0E4e;Da4",
        "70hCi,E44Df[A4B/J@3f<=:`D",
        "8_Dw\"4#?+3i]q&;p6 gtw88EC",
        "boe]!ai0FB@.:|L6l@A?>qJ}I",
        "g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"
    };

    int i = 0;
    char *str;
    while (i < 15) {
        str = ft_des(tokens[i]);
        printf("%s\n", str);
        i++;
    }

}