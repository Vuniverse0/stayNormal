#include "Handler.h"
#include "Game.h"
#include "../interface/Panel.h"
#include "../objects/Main_Character.hpp"

#include <iostream>


void enable(Button* b = nullptr){
    static Button* button = nullptr;
    if(b)
        button = b;
    else if(button)
        button->enable();
}

int main()
{
    Ui ui;
    Word word;
    Handler handler(&word, &ui);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    Button button0{+[](){std::cout<<"button0";}, "../src/resources/icons/main/research.png"};
    Button button1{+[](){std::cout<<"button2"; enable(); }, "../src/resources/icons/main/map.png"};
    Button button2{+[](){std::cout<<"button3";}, "../src/resources/icons/main/resources.png"};
    Button button3{+[](){std::cout<<"button4";}, "../src/resources/icons/main/space-shuttle.png"};
    Button button4{+[](){std::cout<<"button5";}, "../src/resources/icons/main/radar-dish.png"};
    Button button5{+[](){std::cout<<"button6";}, "../src/resources/icons/main/vortex.png"};
    Button button6{+[](){std::cout<<"button7";}, "../src/resources/icons/main/pause.png"};
    button0.disable();
    enable(&button0);
    std::array<Button*, 7> m_group{&button0, &button1, &button2, &button3, &button4, &button5, &button6};

    Panel leftCenterPanel(m_group,
                          "../src/resources/interface/PNG/MainPanel04.png",
                          0.7f, 1.75f);


    std::array<Gui*, 1> UiMouseButtonReleased{&leftCenterPanel};
    std::array<Gui*, 1> UiMouseMoved{&leftCenterPanel};
    std::array<Gui*, 1> Gui{&leftCenterPanel};

    ui.MouseButtonReleased = {UiMouseButtonReleased};
    ui.MouseMoved = {UiMouseMoved};
    ui.gui = {Gui};

    Main_Character mainCharacter(Main_Character_Skin::Outside);
    mainCharacter.moveWord(0.05, 0.5);

    std::array<Entry*, 1> entries{&mainCharacter};
    std::array<Entry*, 1> MouseButtonReleased{&mainCharacter};

    word.entries = {entries};
    word.MouseButtonReleased = {MouseButtonReleased};

    while (Handler::isOpen()) {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;
        while (timeSinceLastUpdate > Handler::TimePerFrame()) {
            timeSinceLastUpdate -= Handler::TimePerFrame();
            handler.process_events();  ///process events
        }
        handler.update(deltaTime); ///process process_events of game
        handler.render();
    }
    #ifndef NDEBUG
    std::cerr<<"debug" << std::endl;
    #endif
    return 0;
}

#if 0
std::ofstream o("/home/vuniverse/Documents/pretty.json");
#include "Metadata.h"
#include <fstream>
#include "Loader.h"
#include "../objects/System.h"
#include "../utility/random_body.h"
    MetaDataObject obj{
        Body::System,
        {static_cast<unsigned int>(21)},
        {{0},{0}},
        "none.png",
        6,
        "name"
    };
    //Loader::load(Stars::Black);
    //MetaDataBody body;
    json j;
    //to_json(j["System"][0], obj);
    o<<j;
    o.close();
    for (auto i = 0 ; i < 100; ++i) {
        //std::cout << "float " << RANDOM_N_AFTER_POINT(2,20,10.f)<< std::endl;
        //std::cout << "int "<< ((int) binominal_int(1, 10, 0.5)) << std::endl;
    }
#endif