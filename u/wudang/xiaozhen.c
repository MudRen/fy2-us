
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�������䵱ɽ��Ψһ��һ��С��С���Ǻܴ󣬵�ȴ�ܷ�����
�������䵱ɽ�ţ����м�ʹ����Сͯ��Ҳ�Ἰ��̫��ȭ���������С
�򣬾����䵱�ɵ���Դ�ء��䵱ɽ��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"xzroad1",
		"north" : __DIR__"bwuroad2",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
