//mac's chansi.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","�˹�����");
  set("long",@LONG
��ʯ�����ɽ���Ͽ��ţ��˹����¡�����Ʈ��������������һ
�����µĸо���ɽ�����ԵĶ�����������עĿ��
[35m
		ĺ	��
		��	��
		��	��
		��	��
		��	��
		��	��
		��	��
		��	��
		��	��
		��	��
		�ͣ�	�ˡ�	
[37m
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
       ]) );
  set("exits",([
         "southdown":__DIR__"fudi.c",
         "north"    :__DIR__"jinggang.c"
               ]));
   
          set("outdoors", "qianfo");
	setup();
  replace_program(ROOM);
}
