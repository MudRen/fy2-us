
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ѿ������ֵı�Ե��һ��СϪ��������Ծ�����������֣���һ������
�֣�СϪ�Ͱ�����������͸�����ֵķ�϶������Կ���һЩ�ߴ�ͦ�ε�������
��Լ�ɼ�һЩ���߰�ǽ������¥��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"huding",
  "north" : __DIR__"bamboo2",
]));
        set("outdoors", "palace");
        set("resource/water",1);
        setup();
        replace_program(ROOM);
}

