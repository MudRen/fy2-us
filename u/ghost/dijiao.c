
inherit ROOM;

void create()
{
	set("short", "�ؽ�");
	set("long", @LONG
�ؽ��ﺮ�����ʪ��������ǽ���Ϲ���һյ�͵ơ��谵�ĵƹ��£�
������Ե���ɭ�ɲ����ؽ�����һ�����ӣ������϶˶�����������һ
���ˡ�
LONG
	);
	set("exits", ([
                "down" : __DIR__"dijiao2",
	]));
	set("objects", ([
                __DIR__"npc/biaoge" : 1,
	]));
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
