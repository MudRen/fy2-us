
inherit ROOM;

void create()
{
        set("short", "�Ʒ���");
        set("long", @LONG
һ�䶫�������С�ݣ��������������õ��ư�ʣ����ϵ�ϲ��д���������ſ���
���ſ�����˳�ۣ�ǽ�����ŵĲ���ү���õ�����һ����������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"inn",
]));
        set("objects", ([
        "/obj/xiaotong" : 3,
                        ]) );
       setup();
        replace_program(ROOM);

}

