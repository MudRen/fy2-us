
inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
����һ������������������Ƕ��ͭ�ơ���бб��������£���֪
�ж೤��Ҳ��֪����δ���������ͭ�ƾ㶼���ü�Ϊ�������Լ��˵ؾ�����
�����ߡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secretpath1",
  "west" : __DIR__"kengdi",
]));

        setup();
        replace_program(ROOM);
}

