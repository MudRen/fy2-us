// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
ʯ���о���һ��С·���������ۣ����������������ٶ��߼���
Ҳ�޷���������......����֮������˭�������Ҳ�������׳�ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
  "west" : __DIR__"road4",
  "northwest" : __DIR__"deep",
]));

        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}