
inherit ROOM;

void create()
{
        set("short", "����ǰ");
        set("long", @LONG
����·�ԵĲݵأ����¹�����ֻ��·��һ�����ᣬ�����ڴ���֮�䣬΢��
������������ɡ���Զ�������������ɽ����һƬС�ɵ�¥�󣬷�������
����������������ʹ�һ�㡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"house2",
  "east" : __DIR__"bamboo",
  "north" : __DIR__"valley",
]));
        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

