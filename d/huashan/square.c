// square.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����ǻ�ɽ�ɵ����䳡��ͨ������໪ɽ�ɵ����ڴ�ϰ������������
����ӭ���ˡ����񣬻�ɽ�ɲ�֪Ϊ�ξ�����ɽ��ȥ��ֻ���������ӿ��ң�
�����ƺ����Ĺ���ô�࣬����Щ�ο��ڴ���Ϣ�����ߵķ������Ϲ���һ��
�ң����顸������Ϊ�����������ǻ�ɽ�ɵ��Ӵ�ű����ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"yunu",
		"north" : __DIR__"buwei1",
		"east" : __DIR__"bingqifang",
		"west" : __DIR__"xiaodian",
	]));

	set("objects", ([ 
		__DIR__"npc/dayou" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	setup();
	replace_program(ROOM);
}
