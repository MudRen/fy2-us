#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����Ҳ�ƽ��ã�����˵�𷨼���֮�أ��м�Ϊʨ��������ǰΪ��
�Σ���Ϊ����������Ϊ�����𷨵�ʨ��ͼ����������������������ϯ
�ϣ�������ӣ��ұ���С�ģ�Ϊ����˵��ʱ��֮��
LONG
  );
  set("exits",([
            "east":__DIR__"mile.c",
               ]));
        set("objects", ([
                __DIR__"npc/bonze4" : 1,
       ]) );
  setup();
  replace_program(ROOM);
}
