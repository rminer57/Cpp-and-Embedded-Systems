// SequenceCommandBaseClass.h: interface for the SequenceCommandBaseClass class.
//
//////////////////////////////////////////////////////////////////////



#if !defined(AFX_SEQUENCECOMMANDBASECLASS_H__540978D4_7D15_11D5_8C74_00C04F556625__INCLUDED_)
#define AFX_SEQUENCECOMMANDBASECLASS_H__540978D4_7D15_11D5_8C74_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>

//User defined struct
struct RegisterType
{
	bool source_type;
	int ext;
	int num;
};

class SequenceCommandBaseClass //: public CObject 
{
public:
	int getGroupNum();
	void setGroupNum(int groupNum);
	bool getIsSelected();
	void setIsSelected(bool selected);
	void setComplete(bool complete);
	bool getComplete();
  SequenceCommandBaseClass();
	virtual ~SequenceCommandBaseClass();
	
  // Data get/set functions
  int getOpcode();
	void setOpcode(int operation);

  bool getImmediate();
	void setImmediate(bool immd);

	void setLabel(CString label);
  CString getLabel();

	void setComment(CString comment);
	CString getComment();
	
	// Save function(s)
	virtual void Serialize(CArchive& ar);

  // String name functions
  virtual CString getOpcodeName();    // return opcode name
  virtual CString toString();         // return asm representation of command

  // Public data members
  const static CString invalidString; // if a command was invalid, generate a comment
                                      // in the assembly file that says there was an
                                      // invalid instruction

  static CString getRegString(RegisterType regData);

protected:
  // Private data members
	CString label_string;     // String containing this command's label
	CString comment_string;   // String containing this command's comments
	bool immediate;           // True if immediate data
	int opcode;               // Opcode representing command type
	bool isComplete;		  // Boolean value that is true is all information is complete.
	bool isSelected;		  // Boolean value that is true when it has been selected.  (This
							  // will be used primarily for the drawing methods.
	int group_num;			  // This integer value will store what group the object is in.
							  // (if any)  This will be used strictly for drawing purposes.
};

#endif // !defined(AFX_SEQUENCECOMMANDBASECLASS_H__540978D4_7D15_11D5_8C74_00C04F556625__INCLUDED_)
