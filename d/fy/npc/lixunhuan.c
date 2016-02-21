// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��Ѱ��", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"С��ɵ�"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);

        set("rank_info/respect", "��̽��");

        set("long",
"��Ѱ�������̽�������н����º�С��ɵ���
һ�ַɵ��������ڰ������ı����������е�����
�������ѣ��������鷢��\n"                
	);
        create_family("����һ��", 2, "�˽�");
	set("student_title","�˽�");
        set("combat_exp", 10000000);
        set("score", 200000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "��Ѱ����ͣ���ڿȣ��������һ˿��Ѫ��\n",
                "��Ѱ������ɫԽ���԰��ˡ�\n",
"��Ѱ��̾���������������������ľ��\n",
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "xiaoli-feidao" :)
        }) );

        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
	set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);

       map_skill("throwing", "feidao");


        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/xlfd_knife")->wield();
}

void attempt_apprentice(object ob)
{
	if(time()-(int) ob->query("last_time_app_master_li") < 600)
	{
	         message_vision("$NЦ��������ô��ô���ֻ����ˣ�����\n",
        this_object());
        return;
        }
	if((int) ob->query("force_factor") < 100)
	{
	 message_vision("$NЦ��������书���˽⻹����������\n",
        this_object());
	return;

	}
	if( random(100) || random((int)ob->query("kar")) <  25 ||
	   query("already"))
	{
	message_vision("$N����������˵������Ҫ����Ц���ҿɲ��������ӵܡ�\n",
	this_object());
	ob->set("last_time_app_master_li",time());
                return;
        }
        command("sigh");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"�����в���Ϊ��������\n");
        command("recruit " + ob->query("id") );
	ob->delete("betrayer");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
	set("already",1);
}
void reset()
{
	set("already",0);
} 
void init()
{
        add_action("give_quest", "quest");
}

