#!/bin/bash
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Checks commit messages against project standards in CONTRIBUTING.md document
# Script to determine if commit messages in Pull Request are properly formatted.
# Exits with non 0 exit code if reformatting is needed.
#
# Author: Mark Lobodzinski <mark@lunarg.com>

# Disable subshells
shopt -s lastpipe

HELP_MSG='\033[0;96m'
SUCCESS_MSG='\033[0;32m'
CONTENT='\033[0;39m'
ERR_MSG='\033[0;93m'
NC='\033[0m' # No Color

# TRAVIS_COMMIT_RANGE contains range of commits for this PR

# Get user-supplied commit message text for applicable commits and insert
# a unique separator string identifier. The git command returns ONLY the
# subject line and body for each of the commits.
TRAVIS_COMMIT_RANGE="${TRAVIS_COMMIT_RANGE/.../..}"
COMMIT_TEXT=$(git log ${TRAVIS_COMMIT_RANGE} --pretty=format:"XXXNEWLINEXXX"%n%B)

# Bail if there are none
if [ -z "${COMMIT_TEXT}" ]; then
  echo -e "${SUCCESS_MSG}No commit messgages to check for formatting.${NC}"
  exit 0
elif ! echo $TRAVIS_COMMIT_RANGE | grep -q "\.\.\."; then
  echo -e "${SUCCESS_MSG}No commit messgages to check for formatting.${NC}"
  exit 0
fi

# Process commit messages
success=1
current_line=0
prevline=""

# Process each line of the commit message output, resetting counter on separator
printf %s "$COMMIT_TEXT" | while IFS='' read -r line; do
  # echo "Count = $current_line <Line> = $line"
  current_line=$((current_line+1))
  if [ "$line" = "XXXNEWLINEXXX" ]; then
    current_line=0
  fi
  chars=${#line}
  if [ $current_line -eq 1 ]; then
    # Enforce subject line must be 64 chars or less
    if [ $chars -gt 64 ]; then
      echo -e "${ERR_MSG}The following subject line exceeds 64 characters in length.${NC}"
      echo -e "${CONTENT}     '$line'${NC}\n"
      success=0
    fi
    i=$(($chars-1))
    last_char=${line:$i:1}
    # Output error if last char of subject line is not alpha-numeric
    if [[ $last_char =~ [.,] ]]; then
      echo -e "${ERR_MSG}For the following commit, the last character of the subject line must not be a period or comma.${NC}"
      echo -e "${CONTENT}     '$line'${NC}\n"
      success=0
    fi
    # Ignore 'Revert' commits
    prefix=$(echo $line | cut -f1 -d " ")
    if [ "${prefix}" != "Revert" ]; then
      # Output error if subject line doesn't start with 'module: '
      if [ "${prefix: -1}" != ":" ]; then
        echo -e "${ERR_MSG}The following subject line must start with a single word specifying the functional area of the change, followed by a colon and space.${NC}"
        echo -e "${ERR_MSG}e.g., 'layers: Subject line here' or 'corechecks: Fix off-by-one error in ValidateFences'${NC}"
        echo -e "${ERR_MSG}Other common module names include layers, build, cmake, tests, docs, scirpts, stateless, gpu, syncval, practices, etc.${NC}"
        echo -e "${CONTENT}     '$line'${NC}\n"
        success=0
      fi
      # Check that first character of subject line is not capitalized
      firstchar=$(echo ${line} | cut -c 1)
      if [[ "${firstchar}" =~ [A-Z] ]]; then
        echo -e "${ERR_MSG}The first word of the subject line must be lower case.${NC}"
        echo -e "${CONTENT}     '$line'${NC}\n"
        success=0
      fi
      # Check if first character after the colon is lower-case
      subject=$(echo $line | cut -f2 -d " ")
      firstchar=$(echo ${subject} | cut -c 1)
      if [[ "${firstchar}" =~ [a-z] ]]; then
        echo -e "${ERR_MSG}The first word of the subject line after the ':' character must be capitalized.${NC}"
        echo -e "${CONTENT}     '$line'${NC}\n"
        success=0
      fi
    fi
  elif [ $current_line -eq 2 ]; then
    # Commit message must have a blank line between subject and body
    if [ $chars -ne 0 ]; then
      echo -e "${ERR_MSG}The following subject line must be followed by a blank line.${NC}"
      echo -e "${CONTENT}     '$prevline'${NC}\n"
      success=0
    fi
  else
    # Lines in a commit message body must be less than 72 characters in length (but give some slack)
    if [ $chars -gt 76 ]; then
      echo -e "${ERR_MSG}The following commit message body line exceeds the 72 character limit.${NC}"
      echo -e "${CONTENT}     '$line'${NC}\n"
      success=0
    fi
  fi
  prevline=$line
done

if [ $success -eq 1 ]; then
  echo -e "${SUCCESS_MSG}All commit messages in pull request are properly formatted.${NC}"
  exit 0
else
  echo -e "${HELP_MSG}"
  echo -e "Commit Message Format Requirements:"
  echo -e "-----------------------------------"
  echo -e 'o  Subject lines must be <= 64 characters in length'
  echo -e 'o  Subject lines must start with a module keyword which is lower-case and followed by a colon and a space'
  echo -e "o  The first word following the colon must be capitalized and the subject line must not end in a '.'"
  echo -e 'o  The subject line must be followed by a blank line'
  echo -e 'o  The commit description must be <= 72 characters in width'
  echo -e ''
  echo -e 'Examples:'
  echo -e '---------'
  echo -e '     build: Fix Vulkan header/registry detection for SDK'
  echo -e '     tests: Fix QueryPerformanceIncompletePasses stride usage'
  echo -e '     corechecks: Fix validation of VU 03227'
  echo -e "     state_tracker: Remove 'using std::*' statements"
  echo -e '     stateless: Account for DynStateWithCount for multiViewport'
  echo -e ''
  echo -e "Refer to this document for additional detail." 
  echo -e "https://github.com/KhronosGroup/Vulkan-ValidationLayers/blob/master/CONTRIBUTING.md#coding-conventions-and-formatting"
  echo -e "${NC}"
  exit 1
fi
