
inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭����
���㣬��������֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,
������Ȼ���¡� 
LONG
	);
	set("exits", ([
		"north" : __DIR__"farm4",
		"south" : __DIR__"farm6",
		"west" : __DIR__"road1",
		"east" : __DIR__"farm4",
	]));
	set("objects", ([
		__DIR__"npc/farmer2" : 1,
	]));
	set("outdoors", "wudang");
	setup();
replace_program(ROOM);

}