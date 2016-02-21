// servant.c

inherit NPC;
inherit F_MASTER;
inherit F_VENDOR;
inherit F_CLEAN_UP;

void create()
{
        set_name("����", ({ "master tjb", "tjb", "master" }) );
        set("title", "������ʿ");
        set("nickname", "����");
        set("gender", "����");
        set("age", 24);
        set("long",
                
"������������Ϊ��promote�������뵱��ʦ�����, ��Ϊ�����æֻ������NPC\n"
                
"�������ˣ�����£���Ҳϣ����Ϊ��������(list tjb1)\n��������ʦ��apply\n"
"ѯ������ask master about all\n");
        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("vendor_goods", ([
               "��Ƭ":  "/obj/example/tjbcard",
           ]) );  
        set("score", 200000);
        set("env/wimpy",70);
        set("env/ppp","tjb");
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 30);

        set("inquiry", ([
                "��ѧ": "��ѧ֮��....��....ֻ����ᣬ����������\n",
                "��ʦ": 
"Ŷ....�������и���أ����������Ϊʦ�ģ��ý���һ�в�������������(accept 
test tjb1)��\n",
                "all" : "��ʦ, ��ѧ, ���룿\n",
                "����" : "����ֻΪplayer������Ϊapprentice\n",
        ]) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        create_family("������", 2, "����");
        assign_apprentice("����", 0);

        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 180);
        set_skill("parry", 100);
        set_skill("dodge", 150);
        set_skill("throwing", 50);
        set_skill("literate",100);

        set_skill("demon-force", 150);
        set_skill("doomsword", 120);
        set_skill("fall-steps", 150);

        map_skill("force", "demon-force");
        map_skill("sword", "doomsword");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/d/wanmei/npc/obj/xuejian")->wield();
        add_money("gold",100);
}

void init()
{
   object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting()) {
            remove_call_out("greeting");
            call_out("greeting",1,ob);
        };
        add_action("do_accept", "accept");
        add_action("do_vendor_list","list"); 
}


int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
                say("\n�������˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        
say("����̾�˿�����˵������һ�ж��Ų����������Բ�����....\n");
                        return 1;
                }
say("\n����������Ц��˵����������������ٵ�һ������֮�ţ�\n\n");
                command("recruit " + this_player()->query("id") );
                return 1;
        }
        return 0;
}

 
void attempt_apprentice(object me)
{
	say(RANK_D->query_respect(me) + "��������ģ��������ҿ��������ѧ\n");
	
	tell_object(me, "������ʦ�Ļ���������ܲ��ԣ�accept test��\n");
}	 

void greeting(object ob)
{
  if (!ob || environment(ob) != environment()) return;
    say("����˵��: ��λ"+RANK_D->query_respect(ob)
       +"��ӭ�������߽��� \n");
}

