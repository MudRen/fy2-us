// Room: /d/chuenyu/dustyroad2.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯС·");
        set("long", @LONG
����һ��ͨ��һ����լ����ʯС·��С�ݾ�����Ķ�������һ��
�����С��ƺ����Ķ��ߡ����Ϸ�����һ������·�ڣ����ƺ���������
�����������Ľ�������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"dustyroad2",
  "northeast" : __DIR__"home",
  "north" : __DIR__"smallyard",
]));
        create_door("northeast", "ľ��", "southwest", DOOR_CLOSED);

        set("outdoors", "chuenyu");

        setup();
        replace_program(ROOM);
}

