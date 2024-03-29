#include "UDSServer.hpp"
#include "IOTask_interaction_DDS.hpp"

int main(void){
    Hirain_Deserialization::ObjectEncoderDecoder obed;

    obed.getDDSConfig((char * )"DDS.config.json");

    
    std::vector<std::string> dataConfig={"0x01000",
            "0x00005",
            "0x02000",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x00002",
            "0x010FF",
            "0x01000",
            "0x00002",
            "0x010FF",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x01000",
            "0x01000",
            "0x00002",
            "0x00002",
            "0x010FF",
            "0x010FF",
            "0x010FF",
            "0x01000",
            "0x00002",
            "0x010FF",
            "0x01000",
            "0x00002",
            "0x010FF",
            "0x01000",
            "0x00002",
            "0x010FF",
            "0x00002",
            "0x020FF",
            "0x010FF"};
    obed.curHashCode={151322625,
            151322626,
            151326726,
            151326732,
            151326738,
            151322663,
            151322667,
            151322671,
            151322675,
            151326778,
            151322703,
            151322707,
            0
};
    // 不明白意义(wfl-start)
    char buf[1000]={0};   
    int hashid=151322625;
    memcpy((char *)&buf,(char *)&hashid,4);
    for(int i=0;i<245;++i){
        uint8_t temp=buf[i];
        std::cout<<uint16_t(temp)<<" ";
    }
    std::cout<<std::endl;
    // (wfl-end)

    std::shared_ptr<std::string> depayload = std::make_shared<std::string>();
    uint32_t dataIndex=0;
    obed.decodeMsgPayload(depayload,reinterpret_cast<char *>(buf),dataIndex,dataConfig);
    
    for(int i=0;i<depayload->size();++i){
        uint8_t temp=depayload->at(i);
        std::cout<<uint16_t(temp)<<" ";
    }
    std::cout<<std::endl;

    std::shared_ptr<std::string> enpayload = std::make_shared<std::string>();
    dataIndex=0;
    obed.encodeMsgPayload(enpayload,depayload->data(),dataIndex,dataConfig);

    for(int i=0;i<enpayload->size();++i){
        uint8_t temp=enpayload->at(i);
        std::cout<<uint16_t(temp)<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}
//133 202 38 0 0 0 0 0 113 61 10 215 163 176 40 64 0 0 0 0 0 0 0 0 0 0 
