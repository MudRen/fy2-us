#include <room.h>
inherit ROOM;
void create()
{
  set("short","��Ժ");
  set("long",@LONG
����һ���徻��СԺ��������໨����ľ����������ֻ����涷
�޵Ŀ��ţ���ʹ����Ҳ�а�ѩ�ĺ�÷��������˵���յ��������յľ�
����Ժ�ı�����������Ү���ҡ�
LONG
  );
  set("exits",([
         "east" :__DIR__"changlang4.c",
         "west" :__DIR__"changlang3.c",
         "north":__DIR__"yezhang.c"
               ]));
   
  setup();
  replace_program(ROOM);
}
