
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
ʯ·�ϲ������٣�ƽ��Ǭ����ʯ�壬�����·����궼�����߶�����һ�㱩
¶�ڲ��֮�¡�������һƬ���������֣��������з���¥������Ҳ��һƬ��
�֣���Լ����ˮ֮��������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"sriver",
  "east" : __DIR__"huding",
]));
        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

