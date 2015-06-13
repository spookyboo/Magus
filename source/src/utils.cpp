/****************************************************************************
**
** Copyright (C) 2015
**
** This file is part of the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#include "utils.h"
#include <QTextStream>

//****************************************************************************/
bool Utils::removeDirRecursively(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName))
    {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst))
        {
            if (info.isDir())
            {
                result = removeDirRecursively(info.absoluteFilePath());
            }
            else
            {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result)
            {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }

    return result;
}

//****************************************************************************/
QString Utils::getFileAsString(const QString &fileName)
{
    QFile f(fileName);
    QString s;
    if (f.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&f);
        s.append(in.readAll());
        return s;
    }
    f.close();

    return s;
}


//****************************************************************************/
void Utils::writeStringtoFile(const QString &str, const QString &fileName)
{
    QFile f(fileName);
    if (f.open(QFile::ReadWrite | QFile::Text))
    {
        QTextStream out(&f);
        out << str << endl;
    }
}

//****************************************************************************/
QString Utils::makePrivateAttribute(const QString &name)
{
    QString changedName = name;
    changedName.remove(QRegExp(QString::fromUtf8("[-`~!@#$%^&* ()_—+=|:;<>«»,.?/{}\'\"\\\[\\\]\\\\]"))); // also remove spaces
    changedName.replace(0, 1, changedName.left(1).toUpper());
    changedName = QString("m") + changedName;
    return changedName;
}

//****************************************************************************/
QString Utils::stripSpecialCharacters(const QString &str)
{
    QString s = str;
    s.remove(QRegExp(QString::fromUtf8("[-`~!@#$%^&* ()_—+=|:;<>«»,.?/{}\'\"\\\[\\\]\\\\]"))); // also remove spaces
    return s;
}

//****************************************************************************/
QString Utils::firstCapital(const QString &str)
{
    QString s = str;
    s.replace(0, 1, s.left(1).toUpper());
    return s;
}

//****************************************************************************/
QString Utils::stripExtension(const QString &str)
{
    QString s = str.toLower();
    int pos = s.lastIndexOf(QString("."));
    if (pos >= 0)
    {
        s.remove(pos, 999);
    }
    return s;
}
