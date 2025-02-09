#include "BuilderEnemies.h"

// setupBuilder function 1
//*****************************************************
AbstractEnemy *BuilderEnemies::build() {

    AbstractEnemy *result;

    BuilderEnemies::EnemyType enemyType = (BuilderEnemies::EnemyType) (rand() % 3);
    GameObject::ColorType colorType = (GameObject::ColorType) (rand() % 2);
    BuilderEnemies::SizeType sizeType = (BuilderEnemies::SizeType) (rand() % 3);
    BuilderEnemies::SpeedType speedType = (BuilderEnemies::SpeedType) (rand() % 3);

    switch (enemyType)
    {
        case EnemyType::rectangle:
            result = new RectangleEnemy(this->getLimitUp(), this->getLimitDown(),this->getLimitLeft(), this->getLimitRight(),
                                        colorType, this->selectSpeed(speedType),this->selectSquareSize_width(sizeType),this->selectSquareSize_height(sizeType));
            break;

        case EnemyType::triangle:
            result = new TriangleEnemy(this->getLimitUp(), this->getLimitDown(),this->getLimitLeft(), this->getLimitRight(),
                                        colorType, this->selectSpeed(speedType), this->selectTriamgleSize(sizeType));
            break;
            
        case EnemyType::circle:
        default:
            result = new RectangleEnemy(this->getLimitUp(), this->getLimitDown(),this->getLimitLeft(), this->getLimitRight(),
                                        colorType, this->selectSpeed(speedType),this->selectSquareSize_width(sizeType),this->selectSquareSize_height(sizeType));
            break;
    }
    result->setPosX(this->getLimitRight());
    result->setPosY(rand() % (this->getLimitDown() - this->getLimitUp()) + this->getLimitUp());

    return result;
}

// setupBuilder function 2
//*****************************************************
AbstractEnemy *BuilderEnemies::build(GameObject::ColorType colorType, EnemyType enemyType, 
                                    SizeType sizeType,SpeedType speedType)
{

    AbstractEnemy *result;

    switch (enemyType)
    {
        case EnemyType::rectangle:
            result = new RectangleEnemy(this->getLimitUp(), this->getLimitDown(),this->getLimitLeft(), this->getLimitRight(),
                                        colorType, this->selectSpeed(speedType),this->selectSquareSize_width(sizeType),this->selectSquareSize_height(sizeType));
            break;

        case EnemyType::triangle:
            result = new TriangleEnemy(this->getLimitUp(), this->getLimitDown(),this->getLimitLeft(), this->getLimitRight(),
                                        colorType, this->selectSpeed(speedType), this->selectTriamgleSize(sizeType));
            break;

        case EnemyType::circle:
        default:
            result = this->build();
            break;
    }
    result->setPosX(this->getLimitRight());
    result->setPosY(rand() % (this->getLimitDown() - this->getLimitUp()) + this->getLimitUp());

    return result;
}


// Function getSquareSize_width
//*****************************************************
int BuilderEnemies::selectSquareSize_width(SizeType sizeType)
{
    int result = 0;
    switch (sizeType)
    {
        case SizeType::small:
            result = this->squareSize_small_width;
            break;
        case SizeType::medium:
            result = this->squareSize_medium_width;
            break;
        case SizeType::large:
            result = this->squareSize_large_width;
            break;
        default:
            result = this->squareSize_medium_width;
            break;
    }
    return result;
}

// Function getSquareSize_height
//*****************************************************
int BuilderEnemies::selectSquareSize_height(SizeType sizeType)
{
    int result = 0;
    switch (sizeType)
    {
        case SizeType::small:
            result = this->squareSize_small_height;
            break;
        case SizeType::medium:
            result = this->squareSize_medium_height;
            break;
        case SizeType::large:
            result = this->squareSize_large_height;
            break;
        default:
            result = this->squareSize_medium_height;
            break;
    }
    return result;
}

// Function selectTriamgleSize
//*****************************************************
int BuilderEnemies::selectTriamgleSize(SizeType sizeType)
{
    int result = 0;
    switch (sizeType)
    {
        case SizeType::small:
            result = this->triangleSize_small;
            break;
        case SizeType::medium:
            result = this->triangleSize_medium;
            break;
        case SizeType::large:
            result = this->triangleSize_large;
            break;
        default:
            result = this->triangleSize_medium;
            break;
    }
    return result;
}

// Function selectSpeed
//*****************************************************
int BuilderEnemies::selectSpeed(SpeedType speedType)
{
    int result = 0;
    switch (speedType)
    {
        case SpeedType::slow:
            result = this->speed_slow;
            break;
        case SpeedType::normal:
            result = this->speed_normal;
            break;
        case SpeedType::fast:
            result = this->speed_fast;
            break;
        default:
            result = this->speed_normal;
            break;
    }
    return result;
}

//*****************************************************
// ACCESS FUNCTIONS TO PRIVATE ATRIBUTES
//*****************************************************
int BuilderEnemies::getLimitUp()
{
    return this->limitUp;
}

void BuilderEnemies::setLimitUp(int value)
{
    this->limitUp = value;
    return;
}

int BuilderEnemies::getLimitDown()
{
    return this->limitDown;
}

void BuilderEnemies::setLimitDown(int value)
{
    this->limitDown = value;
    return;
}

int BuilderEnemies::getLimitLeft()
{
    return this->limitLeft;
}

void BuilderEnemies::setLimitLeft(int value)
{
    this->limitLeft = value;
    return;
}

int BuilderEnemies::getLimitRight()
{
    return this->limitRight;
}

void BuilderEnemies::setLimitRight(int value)
{
    this->limitRight = value;
    return;
}
