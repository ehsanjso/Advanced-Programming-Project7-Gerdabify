#ifndef MUSICHANDLER_H
#define MUSICHANDLER_H

#include "gerdabServer.hpp"
#include "api.hpp"
#include <iostream>
#include <string>
#include <vector>

class musicHandler: public RequestHandler{
    void callback(Request* req, Response* res) {
    	loginHandler* l = loginHandler::getInstance();
    	if(l->check_login(req->getParam("token"))) {
			g_api->enterBrowserMode();
			g_api->goToHome();
			g_api->goToLibrary();
			std::vector<std::string> list_v = g_api->listMusics_full_name();
			std::string list = "";
			for(int i = 0; i < list_v.size(); i++) {
				list += "<li><a href=\"#\">" + list_v[i] + "</a></li>";
			}
	        res->body << "<link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'><link href='https://fonts.googleapis.com/css?family=Sofia' rel='stylesheet' type='text/css'><style>*{margin: 0; padding: 0;}body{background: #191828; color: #435160; font-family: \"Open Sans\", sans-serif;}/* body{background: #191828; color: #efedef; font-family: \"Roboto\", Arial, Helvetica, sans-serif; font-size: 16px; font-weight: 300; letter-spacing: 0.01em; line-height: 1.6em; margin: 0;}*/ h2{color: #FFF; font-family: \"Sofia\", cursive; font-weight: bold; font-size: 3.6em; text-align: center; background-color: #1FCE6D; border-bottom: 1px solid #1FCE6D;}a{color: #435160; text-decoration: none;}.copy_right{bottom: 10px; left: 10px; height: 20px; padding: 2px; border-radius: 3px; background: #FFF; position: absolute; font-size: 14px;}.list{width: 30%; margin-left: 35%; border: 1px solid #1FCE6D; margin-top: 50px;}ul{list-style-type: none; margin: 0; padding: 0;}li{font: 200 20px/1.5 Helvetica, Verdana, sans-serif; text-align: center;}li:last-child{border: none;}li a{text-decoration: none; color: #8193a7; -webkit-transition: font-size 0.3s ease, background-color 0.3s ease; -moz-transition: font-size 0.3s ease, background-color 0.3s ease; -o-transition: font-size 0.3s ease, background-color 0.3s ease; -ms-transition: font-size 0.3s ease, background-color 0.3s ease; transition: font-size 0.3s ease, background-color 0.3s ease; display: block; padding: 5px 0;}li a:hover{font-size: 25px; background: #f6f6f6;}</style><div style=\"border-bottom: 1px solid #1FCE6D;clear: both;height: 55px;\"><h1 style=\"margin: 0;height: 35px;padding-top: 10px;padding-bottom: 10px;text-align:center;font-size: 30px;color: #FFF;width: 300px;float: left;background-color:#1FCE6D;font-family: sans-serif;\">Gerdabify</h1><div><p style=\"margin:auto;height: 40px;text-align:center;padding-top: 15px;padding-left: 30px;padding-bottom: 0;font-size: 20px;color: #1FCE6D;float: left;font-family: sans-serif;\">Logged in as "+ req->getParam("token") +"</p> <a href=\"/\" style=\"float: right;padding: 17px 10px;color: #1FCE6D;background-color: #fafafa;\">Home</a></div></div><div class='list'> <h2>Musics</h2> <ul>"+ list +"</ul></div><p class='copy_right'>powered by jso</p>";
    	} else {
    		res->body << "<link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'><link href='https://fonts.googleapis.com/css?family=Sofia' rel='stylesheet' type='text/css'><style>*{margin: 0; padding: 0;}body{background: #191828; color: #435160; font-family: \"Open Sans\", sans-serif;}/* body{background: #191828; color: #efedef; font-family: \"Roboto\", Arial, Helvetica, sans-serif; font-size: 16px; font-weight: 300; letter-spacing: 0.01em; line-height: 1.6em; margin: 0;}*/ h2{color: #6D7781; font-family: \"Sofia\", cursive; font-size: 15px; font-weight: bold; font-size: 3.6em; margin-top: 18%; text-align: center; margin-bottom: 20px;}a{color: #435160; text-decoration: none;}.copy_right{bottom: 10px; left: 10px; height: 20px; padding: 2px; border-radius: 3px; background: #FFF; position: absolute; font-size: 14px;}</style><div style=\"border-bottom: 1px solid #1FCE6D;clear: both;height: 55px;\"><h1 style=\"margin: 0;height: 35px;padding-top: 10px;padding-bottom: 10px;text-align:center;font-size: 30px;color: #FFF;width: 300px;float: left;background-color:#1FCE6D;font-family: sans-serif;\">Gerdabify</h1><div><p style=\"margin:auto;height: 40px;text-align:center;padding-top: 15px;padding-left: 30px;padding-bottom: 0;font-size: 20px;color: #1FCE6D;float: left;font-family: sans-serif;\">Logged in as ?? :|</p><a href=\"/\" style=\"float: right;padding: 17px 10px;color: #1FCE6D;background-color: #fafafa;\">Home</a></div></div><h2>Something went wrong [login please]!</h2><p class='copy_right'>powered by jso</p>";   

    	}
	}
public:
	musicHandler() {
		g_api = GerdabifyAPI::getInstance();	
	}
private:
	GerdabifyAPI* g_api;
};

#endif