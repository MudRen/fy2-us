//mac's yaocan
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ң��ͤ");
  set("long",@LONG
   �Ӵ��򱱱��ң��̩ɽ����˴�ͤ�ֳ�ң��ͤ�����������鱮������
���ܵ���� �͡��η���̳�̱�����ǰ���������ܵ���޽����飬��������
�������ڵ�̩ɽ���ݴ�л�������顱�������
LONG
  );
  set("exits",([
         "north":__DIR__"daimiao.c",
         "southwest":"/d/chenxiang/road",
               ]));
        set("objects", ([
                __DIR__"npc/jin" : 1,
		__DIR__"npc/tiao" : 2,
       ]) );
        set("item_desc", ([
                "�������ܵ����": "
			��������һ�Σ�������������\n",
                "���η���̳�̱���": "
			��������һ�Σ�������������\n"

        ]) );
  setup();
  replace_program(ROOM);
}
