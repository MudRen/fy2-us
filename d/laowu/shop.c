
inherit ROOM;

void create()
{
        set("short", "��ҩ��");
        set("long", @LONG
�����ﲼ�õþ��Ŷ����£�ÿһ���������Ǿ�����ѡ�ģ����ð�����ǡ���ĵط���
¯���յ���������Ҳ��ú��������������������ִ��ֺ����Ƥ����ů�þ���������
�����µĺ���һ����
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"street1",
]));
        set("objects", ([
        __DIR__"npc/leng" : 1,
                        ]) );

        setup();
        replace_program(ROOM);

}

