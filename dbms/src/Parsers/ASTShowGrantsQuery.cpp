#include <Parsers/ASTShowGrantsQuery.h>
#include <Common/quoteString.h>


namespace DB
{
String ASTShowGrantsQuery::getID(char) const
{
    return "ShowGrantsQuery";
}


ASTPtr ASTShowGrantsQuery::clone() const
{
    return std::make_shared<ASTShowGrantsQuery>(*this);
}


void ASTShowGrantsQuery::formatQueryImpl(const FormatSettings & settings, FormatState &, FormatStateStacked) const
{
    settings.ostr << (settings.hilite ? hilite_keyword : "") << "SHOW GRANTS FOR "
                  << (settings.hilite ? hilite_none : "");

    if (current_user)
        settings.ostr << (settings.hilite ? hilite_keyword : "") << "CURRENT_USER"
                      << (settings.hilite ? hilite_none : "");
    else
        settings.ostr << backQuoteIfNeed(name);
}
}
