inherit ROOM;

void create()
{
        set("short", "ɱ��ͬ���ܶ�");
        set("long",@LONG
����ɱ��ͬ���ܶ档
LONG
        );
        set("outdoors", "shaolin");
        set("exits", ([
//                "northwest" : __DIR__"guangchang",
                "west" : "/d/village/hsroad1",
        ]));
//        set("objects",([
//                __DIR__"npc/zuolengchan" : 1,
//        ]));
        setup();
        replace_program(ROOM);
}
