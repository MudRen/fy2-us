// teacher.c

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("����", ({ "meng", "cha meng" }) );
	set("title", HIY "��ʨ��" NOR);
	set("gender", "����" );
	set("age", 42);
	set("skill_public",1);
	set("int", 30);
        create_family("�����׼�", 21, "����");
	set("long",
		"��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
		 ������������̵ģ�ֻҪΪ�ھֳ����������ͿϽ̣�\n"
		);
       set("chat_chance", 1);
        set("chat_msg", ({
                "����˵����������ھ����ⲻ��\n",
        }) );
	set("attitude", "peaceful");
	set_skill("unarmed", 30);
	set_skill("changquan", 30);
	set_skill("literate", 30);
	set_skill("force", 30);
	set_skill("dodge",30);
	set_skill("parry",30);
	map_skill("unarmed", "changquan");
	set("combat_exp", 90000);
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
}
int recognize_apprentice(object ob)
{
        if((time() - ob->query("marks/��ʨ") ) > 1800  ){
                say("����˵�����㣮�������ܾ�ûΪ�ھֳ�������....\n");
                return 0;
        }

        return 1;
}
