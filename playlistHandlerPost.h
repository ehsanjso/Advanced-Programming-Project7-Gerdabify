#ifndef PLAYLISTSHANDLERPOST_H
#define PLAYLISTSHANDLERPOST_H

#include "gerdabServer.hpp"
#include "api.hpp"
#include "error.h"
#include <iostream>

class playlistsHandlerPost: public RequestHandler{
    void callback(Request* req, Response* res) {
    	loginHandler* l = loginHandler::getInstance();
    	if(l->check_login(req->getParam("token"))) {
    		try {
				g_api->createPlaylist(req->getParam("name"));
				res->body << "<link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'><link href='https://fonts.googleapis.com/css?family=Sofia' rel='stylesheet' type='text/css'><style>*{margin: 0; padding: 0;}body{background: #191828; color: #435160; font-family: \"Open Sans\", sans-serif;}/* body{background: #191828; color: #efedef; font-family: \"Roboto\", Arial, Helvetica, sans-serif; font-size: 16px; font-weight: 300; letter-spacing: 0.01em; line-height: 1.6em; margin: 0;}*/ h2{color: #6D7781; font-family: \"Sofia\", cursive; font-size: 15px; font-weight: bold; font-size: 3.6em; margin-top: 18%; text-align: center; margin-bottom: 20px;}a{color: #435160; text-decoration: none;}.copy_right{bottom: 10px; left: 10px; height: 20px; padding: 2px; border-radius: 3px; background: #FFF; position: absolute; font-size: 14px;}</style><div style=\"border-bottom: 1px solid #1FCE6D;clear: both;height: 55px;\"><h1 style=\"margin: 0;height: 35px;padding-top: 10px;padding-bottom: 10px;text-align:center;font-size: 30px;color: #FFF;width: 300px;float: left;background-color:#1FCE6D;font-family: sans-serif;\">Gerdabify</h1><div><p style=\"margin:auto;height: 40px;text-align:center;padding-top: 15px;padding-left: 30px;padding-bottom: 0;font-size: 20px;color: #1FCE6D;float: left;font-family: sans-serif;\">Logged in as " + req->getParam("token") + "</p><a href=\"/\" style=\"float: right;padding: 17px 10px;color: #1FCE6D;background-color: #fafafa;\">Home</a></div></div><h2>playlist : " + req->getParam("name") + " created!</h2><p class='copy_right'>powered by jso</p>";   
			} catch(AlreadyExists e) {
				res->body << "<link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'><link href='https://fonts.googleapis.com/css?family=Sofia' rel='stylesheet' type='text/css'><style>*{margin: 0; padding: 0;}body{background: #191828; color: #435160; font-family: \"Open Sans\", sans-serif;}/* body{background: #191828; color: #efedef; font-family: \"Roboto\", Arial, Helvetica, sans-serif; font-size: 16px; font-weight: 300; letter-spacing: 0.01em; line-height: 1.6em; margin: 0;}*/ h2{color: #6D7781; font-family: \"Sofia\", cursive; font-size: 15px; font-weight: bold; font-size: 3.6em; margin-top: 18%; text-align: center; margin-bottom: 20px;}a{color: #435160; text-decoration: none;}.copy_right{bottom: 10px; left: 10px; height: 20px; padding: 2px; border-radius: 3px; background: #FFF; position: absolute; font-size: 14px;}</style><div style=\"border-bottom: 1px solid #1FCE6D;clear: both;height: 55px;\"><h1 style=\"margin: 0;height: 35px;padding-top: 10px;padding-bottom: 10px;text-align:center;font-size: 30px;color: #FFF;width: 300px;float: left;background-color:#1FCE6D;font-family: sans-serif;\">Gerdabify</h1><div><p style=\"margin:auto;height: 40px;text-align:center;padding-top: 15px;padding-left: 30px;padding-bottom: 0;font-size: 20px;color: #1FCE6D;float: left;font-family: sans-serif;\">Logged in as " + req->getParam("token") + "</p><a href=\"/\" style=\"float: right;padding: 17px 10px;color: #1FCE6D;background-color: #fafafa;\">Home</a></div></div><h2>playlist : " + req->getParam("name") + " Already Exists!</h2><p class='copy_right'>powered by jso</p>";   
			}
		} else {
    		res->body << "<link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,700' rel='stylesheet' type='text/css'><link href='https://fonts.googleapis.com/css?family=Sofia' rel='stylesheet' type='text/css'><style>*{margin: 0; padding: 0;}body{background: #191828; color: #435160; font-family: \"Open Sans\", sans-serif;}/* body{background: #191828; color: #efedef; font-family: \"Roboto\", Arial, Helvetica, sans-serif; font-size: 16px; font-weight: 300; letter-spacing: 0.01em; line-height: 1.6em; margin: 0;}*/ h2{color: #6D7781; font-family: \"Sofia\", cursive; font-size: 15px; font-weight: bold; font-size: 3.6em; margin-top: 18%; text-align: center; margin-bottom: 20px;}a{color: #435160; text-decoration: none;}.copy_right{bottom: 10px; left: 10px; height: 20px; padding: 2px; border-radius: 3px; background: #FFF; position: absolute; font-size: 14px;}</style><div style=\"border-bottom: 1px solid #1FCE6D;clear: both;height: 55px;\"><h1 style=\"margin: 0;height: 35px;padding-top: 10px;padding-bottom: 10px;text-align:center;font-size: 30px;color: #FFF;width: 300px;float: left;background-color:#1FCE6D;font-family: sans-serif;\">Gerdabify</h1><div><p style=\"margin:auto;height: 40px;text-align:center;padding-top: 15px;padding-left: 30px;padding-bottom: 0;font-size: 20px;color: #1FCE6D;float: left;font-family: sans-serif;\">Logged in as ?? :|</p><a href=\"/\" style=\"float: right;padding: 17px 10px;color: #1FCE6D;background-color: #fafafa;\">Home</a></div></div><h2>Something went wrong [login please]!</h2><p class='copy_right'>powered by jso</p>";   
    	}
    }
public:
	playlistsHandlerPost() {
		g_api = GerdabifyAPI::getInstance();	
	}
private:
	GerdabifyAPI* g_api;
};

#endif