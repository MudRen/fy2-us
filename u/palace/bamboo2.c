
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�����ӵ����磬����͸��ï�ܴ��̵���Ҷ���·�Ⱦ���˵�������
ɫ��һ��СϪ�����ĵش�����Ƭ���֣��ƺ�����ˮ�������ƻ��������������
��������ȴ�˽������ն����������������
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"bamboo3",
  "north" : __DIR__"bamboo",
]));
        set("outdoors", "palace");
        set("resource/water",1);
        setup();
        replace_program(ROOM);
}

