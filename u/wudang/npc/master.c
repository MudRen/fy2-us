// taolord.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ʯ��", ({ "master shi", "master", "shi" }) );
        set("nickname", "��������");
        set("gender", "����");
        set("age", 62);
        set("long",
"ʯ���˵����䵱���ţ�����̫���ķ������Ž����������˼��ߵľ��硣\n"
                "�����侫̫ͨ�����У����������ǵ�����˫�������˳ƣ��������ˣݡ�\n");
        set("combat_exp", 200000);
        set("score", 20000);

        set("class", "taoist");

        set("str", 20);
        set("int", 30);
        set("cor", 20);
        set("cps", 30);
        set("spi", 30);

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);

        set("atman", 400);
        set("max_atman", 400);

        set("mana", 200);
        set("max_mana", 200);

        set("inquiry", ([
                "̫���ķ�": 
"̫���ķ��˵������ŵĻ����ķ����ܹ��������ڵ�����������\n����ֻҪ��֮�Ժ㣬��������κ������ڹ���\n",
                "�䵱��": 
"���䵱���������˿�ɽ����������������������������Ϊ���Ρ�\n"
        ]) );

        set("apprentice_available", 10);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("�䵱��", 57, "������");

        set_skill("literate", 90);
        set_skill("force", 80);
        set_skill("move", 100);
        set_skill("unarmed", 70);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("dodge", 90);
        set_skill("changelaw", 90);
        set_skill("three-sword", 90);
	set_skill("taijiforce", 90);
	set_skill("taiji", 90);
	set_skill("five-steps", 90);

        map_skill("parry", "three-sword");
        map_skill("sword", "three-sword");
        map_skill("literate", "changelaw");
        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji");

        setup();

	carry_object(__DIR__"obj/msword")->wield();
        carry_object(__DIR__"obj/mcloth")->wear();
        carry_object(__DIR__"obj/mhat")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("marks/�䵱��ͽ") )
                command("say " + ob->query("name") + "���㻹�����������ң�");
        else {
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        add("apprentice_availavble", -1);
}

int accept_object(object who, object ob)
{
	object 		book;

        if((string)ob->name() != "���Ʒɵ��غ�") return 0;
	command("say ��л��λ" + RANK_D->query_respect(who));
	command("say �Ȿ������������ɡ�");
	book = new(__DIR__"obj/wubook");
	book->move(this_object());
	command("give book to " + who->query("id"));
        return 1;
}

void init()
{
        add_action("give_quest", "quest");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","�䵱�ɵ�ʿ");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","�䵱��С����");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","�䵱������");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","�䵱��С��ʦ");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","�䵱����ʦ");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","�䵱�ɴ���ʦ");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","�䵱�ɸ�����");
                return ;
        } else
                student->set("title","�䵱������");
                return ;
}

