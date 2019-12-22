#ifndef EARTHEND_H
#define EARTHEND_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Download.h"
#include "Background.h"
#include "Camera.h"
#include "P4A.h"
#include "AnimatedObject.h"
#include "MD5.h"
#include <iostream>
#include <windows.h>
#include <sstream>
#include <thread>
#include "Bundle/Bundle.h"

using namespace std;

class Earthend
{
    public:
    Download download;
    Camera camera;
    P4A handle;
    AnimatedObject a_baby;
    Bundle bundle;

    bool fr = false;
    int mouseX,mouseY;
    bool mouseLeftClick;
    bool tlaunched = false;

    thread downloadThread;
    sf::Clock restart_clock;
    sf::Clock timeout_clock;

    ///FIRST-RUN
    sf::Font FR_p4kaku; ///font
    sf::Texture FR_t_box,FR_t_dots; ///install dir
    sf::Texture FR_t_checkbox,FR_t_mark; ///desktop shortcut
    sf::Texture FR_t_pon,FR_t_eye; ///patapon loading animation

    sf::Sprite FR_box,FR_dots;
    sf::Sprite FR_checkbox,FR_mark;
    sf::Sprite FR_checkbox2,FR_mark2;
    sf::Sprite FR_pon1,FR_eye1;
    sf::Sprite FR_pon2,FR_eye2;

    sf::Text FR_tx_firstrun1;
    sf::Text FR_tx_firstrun2;
    sf::Text FR_tx_installdesc;
    sf::Text FR_tx_installdir;
    sf::Text FR_tx_desktop;
    sf::Text FR_tx_startmenu;
    sf::Text FR_tx_install;
    sf::Text FR_tx_installinfo;
    sf::Text FR_tx_downloading1;
    sf::Text FR_tx_downloading2;
    sf::Text FR_tx_status;

    sf::Text FR_tx_finished;
    sf::Text FR_tx_runlauncher;
    sf::Text FR_tx_exit;

    bool b_desktop = true;
    bool b_startmenu = true;
    bool b_run = true;
    string installdir = "";

    bool exit_launcher = false;

    ///Regular mode
    sf::Font p4kaku;
    sf::RectangleShape rect_1,rect_2;

    sf::Texture tex_logo,tex_box,tex_sword,tex_pata,tex_eye;
    sf::Sprite s_logo,s_loginbox,s_emailbox,s_passbox;

    sf::Text t_username,t_email,t_password;
    sf::Text t_newsheader,t_news;
    sf::Text t_login,t_create,t_playoffline;
    sf::Text t_version;

    float fps;
    int state = 0;

    string web_file_list;

    vector<string> web_files; ///web file location
    vector<string> web_hashes; ///web file hash
    vector<string> web_sizes; ///web file size

    vector<string> local_files; ///local file location

    vector<string> files_download; ///file to download
    vector<string> files_remove; ///files to remove

    bool finish = false;
    Background test_bg;

    Earthend();

    bool file_exists(string file);
    void getWebFileList();
    void getLocalFileList(const char* dirn);
    string getFileHash(string filename);
    vector<string> split(const std::string &s, char delim);
    void splitWebFileList();
    void verifyFiles();
    void downloadFile();
    void FirstRunDownload();

    void Init(sf::RenderWindow& window);
    ~Earthend();
};

#endif // EARTHEND_H
