// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����򱱽�");
        set("long", @LONG
�ֵ��ɰ���ɫ��ʯש�̳ɡ�������Ĵ󲿷ַ��ݶ���������ʯש����
�ġ��ֵ������պÿ�����һ��������ͨ����������һ��СС����ҩ�ꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"cx2",
  "southeast" : __DIR__"cx4",
  "west" : __DIR__"yao",
]));
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
