// buwei1.c

inherit ROOM;

int valid_leave();

void create()
{
        set("short", "����");
	set("long", @LONG
���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ���
�������á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ�
����������Ⱥ���¡���ͽ�ĵط������������ҡ�
LONG
        );

	set("valid_startroom", 1);

        set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"square",
		"north" : __DIR__"buwei2",
	]));

        set("objects", ([ 
		CLASS_D("huashan") + "/linghu" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
//	"/clone/board/huashan_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir != "north")
		return ::valid_leave(me, dir);

        if (dir == "north" && objectp(present("ling huchong", environment(me))))
	{
		if ((me->query("family/family_name") == "��ɽ��"))
        	{
			if ((me->query("gender") == "����"))
				write("���������ÿ���˵����ʦ�������ˣ�ʦ�����������ˡ�\n");
			else if ((me->query("gender") == "Ů��"))
				write("���������ÿ���˵����ʦ�������ˣ�ʦ�����������ˡ�\n");
			return 1;
        	}
		if( present("yingxiong ling", me) && ((int)me->query("shen") > 5000))
		{
			write("����幪��˵����ԭ���ǹ�ͼݵ�����������\n");
			return 1;
		}
                else 
			return notify_fail(
"�����ȵ��������Ǽ�ʦ���ң���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
	}
	return ::valid_leave(me, dir);
}