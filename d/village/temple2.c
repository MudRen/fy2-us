// Room: /d/village/temple2.c

inherit ROOM;

void create()
{
        set("short", "С����");
	set("long", @LONG
����һ����ʱ��������С���ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"temple1",
]));
        set("objects", ([
                __DIR__"npc/wang": 1
        ]) );
        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
	if( me->query_temp("marks/��") ) {
		me->delete_temp("marks/��");
	}
	return 1;
} 
