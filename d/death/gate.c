// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIW "���Ź�" NOR);
        set("long", 
                "�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
                
"��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
                "�������ˡ�\n");
        set("exits", ([
                "north" : "/d/death/gateway",
        ]) );
        set("objects", ([
                __DIR__"npc/wgargoyle":1
        ]) );
        setup();
        replace_program(ROOM);
}
 
