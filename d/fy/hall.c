// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����콾��");
        set("long", @LONG
����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬
�绯��������˵������ʴ���ٷ��ѽ����¶�ŮӢ�۵ĵط������Ǳ���
����Ӣ�۶���Ϊ����֮��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"ecloud5",
]));
        set("objects", ([
        __DIR__"npc/player1" : 1,
        __DIR__"npc/player2" : 1,
        __DIR__"npc/player3" : 1,
        __DIR__"npc/player4" : 1,
        __DIR__"npc/player5" : 1,
        __DIR__"npc/player6" : 1,
        __DIR__"npc/player7" : 1,
        __DIR__"npc/player8" : 1,
        __DIR__"npc/player9" : 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
