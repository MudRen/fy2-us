// promote.c

inherit F_CLEAN_UP;
object make_body(object ob);
int main(object me, string arg)
{
object user,ob;
 seteuid(ROOT_UID);
 user = new("/obj/test.c");
 user->restore();
 user->move(environment(me));
	return 1;
}
int help(object me)
{
write(@HELP
testing
HELP
    );
    return 1;
}
object make_body(object ob)
{
        string err;
        object user;
        int n;
        if (! ob->query("id")) return 0;
        user = new(USER_OB);
        if(!user) return 0;
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

