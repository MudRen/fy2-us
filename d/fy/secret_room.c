
inherit ROOM;

void create()
{
	object silver;
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ���ƾɵ�С����һ
ЩǬ�ݡ�
LONG
	);

	set("objects", ([
		"/obj/money/silver": 1
	]) );

	setup();
	silver = present("silver",this_object());
	silver->set_amount(random(10000)+1000);	
	silver->set("name", "����");
}
