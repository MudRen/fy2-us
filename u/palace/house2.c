
inherit ROOM;

void create()
{
        set("short", "¥��ǰ");
        set("long", @LONG
¥��ǰ��һƬ���������֣�������֣����籯�������ּ伸ֻС��
��ͣ��׷����Ծ�����������ּ����Щ���������������ˣ�ֻ��������
�ۣ�ͨ��һ�ȱ��š�������һ��ʯ·��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"huding",
  "north" : __DIR__"house",
]));
        set("objects", ([
        __DIR__"npc/huafei" : 1,
                        ]) );

        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

