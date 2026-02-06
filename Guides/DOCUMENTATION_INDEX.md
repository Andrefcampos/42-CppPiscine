# Documentation Index

Welcome to the 42 Piscine Object documentation! This index helps you find the right document for your needs.

## 📚 Quick Navigation

### Getting Started
- **[README.md](README.md)** - Project overview and quick start
- **[SETUP.md](SETUP.md)** - Detailed setup instructions and workflow
- **[SUBJECT_README.md](SUBJECT_README.md)** - How to add the subject.pdf

### Coding and Standards
- **[CONTRIBUTING.md](CONTRIBUTING.md)** - 42 School coding standards and contribution guidelines
- **[CODE_REVIEW_GUIDE.md](CODE_REVIEW_GUIDE.md)** - Comprehensive guide for code reviewers
- **[FAQ.md](FAQ.md)** - Frequently asked questions and answers

### Templates and Tools
- **[templates/README.md](templates/README.md)** - Guide to using exercise templates
- **[MODULE_README_TEMPLATE.md](MODULE_README_TEMPLATE.md)** - Template for module documentation
- **[setup_exercise.sh](setup_exercise.sh)** - Automated exercise setup script

### Progress Tracking
- **[PROGRESS.md](PROGRESS.md)** - Track your progress through modules

## 📖 Document Overview

### README.md
**Who**: Everyone
**When**: First thing to read
**Purpose**: Understand the project structure, get started quickly

**Contains**:
- Project overview
- Quick start guide
- File structure
- 42 School Norm basics
- Links to detailed docs

---

### SETUP.md
**Who**: New students, anyone setting up a new environment
**When**: Before starting first exercise
**Purpose**: Complete setup and workflow guide

**Contains**:
- Prerequisites installation
- Step-by-step setup
- Project structure details
- Testing procedures
- Troubleshooting
- Daily workflow

---

### CONTRIBUTING.md
**Who**: All developers, code reviewers
**When**: Before writing or reviewing code
**Purpose**: Ensure code meets 42 School standards

**Contains**:
- 42 School Norm detailed explanation
- Naming conventions
- Forbidden items
- Pull request process
- Code quality standards
- Memory management rules

---

### CODE_REVIEW_GUIDE.md
**Who**: Code reviewers, students doing peer reviews
**When**: During code reviews
**Purpose**: Systematic review checklist

**Contains**:
- Complete review checklist
- What to check for each aspect
- Common issues and solutions
- Example code (good vs bad)
- Review process steps
- Feedback templates

---

### FAQ.md
**Who**: Everyone, especially when stuck
**When**: When you have questions or problems
**Purpose**: Quick answers to common questions

**Contains**:
- General questions
- Getting started help
- Coding standards clarification
- Compilation/testing help
- Common issues and fixes
- Debugging tips
- Resources

---

### templates/README.md
**Who**: Students starting new exercises
**When**: Setting up each new exercise
**Purpose**: Understand and use exercise templates

**Contains**:
- Template file explanations
- How to use templates
- Template features
- Quick start script usage
- Customization tips

---

### MODULE_README_TEMPLATE.md
**Who**: Students documenting modules
**When**: Starting a new module
**Purpose**: Template for creating module READMEs

**Contains**:
- Module documentation structure
- Exercise tracking table
- Key concepts section
- Testing examples
- Notes section

---

### PROGRESS.md
**Who**: Individual students
**When**: Throughout the project
**Purpose**: Track personal progress

**Contains**:
- Module completion checklist
- Exercise status tracking
- Personal goals
- Key learnings
- Review checklist

---

### SUBJECT_README.md
**Who**: Everyone
**When**: Initial setup
**Purpose**: Explain subject.pdf placement

**Contains**:
- Why subject.pdf is important
- How to add it
- Alternative options

## 🎯 Where to Start?

### "I'm brand new to this project"
1. Read [README.md](README.md)
2. Follow [SETUP.md](SETUP.md)
3. Read [CONTRIBUTING.md](CONTRIBUTING.md)
4. Start with Module00

### "I need to set up an exercise"
1. Check [templates/README.md](templates/README.md)
2. Run `./setup_exercise.sh`
3. Read the subject.pdf for that exercise

### "I'm ready to submit code for review"
1. Check your code against [CONTRIBUTING.md](CONTRIBUTING.md)
2. Review the checklist in [CODE_REVIEW_GUIDE.md](CODE_REVIEW_GUIDE.md)
3. Create a pull request

### "I'm reviewing someone's code"
1. Use [CODE_REVIEW_GUIDE.md](CODE_REVIEW_GUIDE.md)
2. Follow the review process
3. Provide constructive feedback

### "I have a question"
1. Check [FAQ.md](FAQ.md)
2. Search the documentation
3. Ask peers (but don't share code!)

### "Something isn't working"
1. Check [FAQ.md](FAQ.md) troubleshooting section
2. Verify compilation flags
3. Run with valgrind/gdb
4. Review error messages carefully

## 📁 File Structure

```
Documentation Files:
├── README.md                    ← Start here
├── SETUP.md                     ← Setup guide
├── CONTRIBUTING.md              ← Coding standards
├── CODE_REVIEW_GUIDE.md         ← Review guidelines
├── FAQ.md                       ← Common questions
├── PROGRESS.md                  ← Track progress
├── SUBJECT_README.md            ← Subject.pdf info
├── MODULE_README_TEMPLATE.md    ← Module doc template
└── templates/
    └── README.md                ← Template usage guide

Configuration Files:
├── .gitignore                   ← Git ignore rules
├── setup_exercise.sh            ← Setup automation
└── .github/
    ├── workflows/               ← GitHub Actions
    ├── ISSUE_TEMPLATE/          ← Issue templates
    └── pull_request_template.md ← PR template

Module Files:
└── ModuleXX/
    ├── README.md                ← Module overview
    └── exYY/
        ├── README.md            ← Exercise details
        ├── Makefile
        ├── *.hpp
        ├── *.cpp
        └── main.cpp
```

## 🔍 Finding Information

### Coding Standards and Style
→ [CONTRIBUTING.md](CONTRIBUTING.md)

### Setup and Installation
→ [SETUP.md](SETUP.md)

### Code Review Checklist
→ [CODE_REVIEW_GUIDE.md](CODE_REVIEW_GUIDE.md)

### Exercise Templates
→ [templates/README.md](templates/README.md)

### Common Problems
→ [FAQ.md](FAQ.md)

### Project Overview
→ [README.md](README.md)

## 💡 Tips

- **Bookmark this index** for quick reference
- **Read the subject.pdf first** before any exercise
- **Follow the workflow** described in SETUP.md
- **Use the templates** to save time and ensure consistency
- **Track your progress** in PROGRESS.md
- **Ask questions** but think first

## 🤝 Contributing to Documentation

If you find:
- Missing information
- Unclear explanations
- Errors or outdated content
- Areas for improvement

Please create an issue or submit a pull request!

## 📞 Getting Help

1. **Check documentation** (start with FAQ.md)
2. **Read subject.pdf** for exercise-specific questions
3. **Search issues** on GitHub
4. **Ask peers** for concept clarification
5. **Consult 42 resources** (intranet, Slack)

**Remember**: Don't share code, but sharing knowledge is encouraged!

---

**Happy coding!** 🚀

The goal is to learn OOP thoroughly, not just complete exercises quickly.
