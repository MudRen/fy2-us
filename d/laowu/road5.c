
inherit ROOM;

void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
���Ƿ��Ƴǵ�һ����Ҫ��������ϴ���ɽ��ˮ��ֱ���ɻ������½ӷ��ƾ�����
��ͨ���Ϻ��ڡ��������������ò�����һ���������Ϸ��ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"laowu",
  "south" : __DIR__"road1",
]));
        set("objects", ([
        __DIR__"npc/trader" : 3,
                        ]) );
        set("outdoors", "laowu");

        setup();
        replace_program(ROOM);

}

