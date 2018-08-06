#include "UiBridge.h"

UiBridge::UiBridge()
{

}

void UiBridge::sentString(QString str)
{
    emit eventSentString(str);
}
