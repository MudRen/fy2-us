inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
���ƹ㳡�ڶ���֪�����������������Ƿ��Ƴ��з�ɧ���˴Ծ�֮�ء���˵����
�պ�������С��̽�������������е���š��ϱߵĿ���ÿ�궼����һ��ѡ�ο��ԣ�
ǰ�������뾩�����ԡ���������̽��ʫ̨���Ƿ�ɧ�������������ǵ���֮���ĵ�
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"poemp",
  "south" : __DIR__"examp",
  "west"  : __DIR__"wcloud2",
  "east"  : __DIR__"fysquare",
]));
        set("objects", ([
        __DIR__"npc/song": 1,
                        ]) );


        set("outdoors", "fengyun");
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me) && dir == "north")
	if( sizeof(me->query_all_condition()) != 0 )
	return notify_fail("̽��ʫ̨������ķس���\n");
	
	return 1;
}
